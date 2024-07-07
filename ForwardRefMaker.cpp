#include "ForwardRefMaker.h"
#include "HonestyChecker.h"
#include <cassert>

int ForwardRefMaker::shift = 5;

size_t ForwardRefMaker::prime[] = {
	14051,
	28111,
	56239,
	112507,
	225023,
	450067,
	900139,
	1800311,
	3600659,
	7201351,
	14402743,
	28805519,
	57611039,
	115222091,
	230444239,
	460888499,
	921777067,
	1843554151,
	UINT64_C(3687108307),
	UINT64_C(7374216631),
	UINT64_C(14748433279),
	UINT64_C(29496866579),
	UINT64_C(58993733159),
	UINT64_C(117987466379),
	UINT64_C(235974932759),
	UINT64_C(471949865531),
	UINT64_C(943899731087),
	UINT64_C(1099511627776),
};

ForwardRefMaker::ForwardRefMaker(std::vector<Text>& texts, std::vector<Token>& tokenVec)
	: _texts(texts), _vector(tokenVec), _vector_length(_vector.size())
{

	assert(&(texts[0].tokenVector()) == &(tokenVec));

	_forward_reference = new size_t[_vector_length]();

	// allocate our temporary hash table
	int n = 0;
	int maxN = sizeof(ForwardRefMaker::prime) / sizeof(size_t);
	while (ForwardRefMaker::prime[n] < _vector_length && n < maxN) {
		++n;
	}
	while (_latest_index == nullptr && n >= 0) {
		_latest_index = new size_t[_hash_table_size = ForwardRefMaker::prime[n]]();
		--n;
	}
	if (!_latest_index) {
		printf("Can't allocate the temporary hash table");
		exit(-1);
	}
}

ForwardRefMaker::~ForwardRefMaker() {
	delete[] _latest_index;
}

bool ForwardRefMaker::isEqualMinRun(size_t i, size_t j) {
	assert((i + HonestyChecker::MinRunSize < _vector.size()) 
		&& (j + HonestyChecker::MinRunSize < _vector.size()));

	size_t offset = 0;
	while (offset < HonestyChecker::MinRunSize) {
		if (_vector[i + offset] != _vector[j + offset]) return false;
		++offset;
	}

	return true;
}

size_t* ForwardRefMaker::run() {

#define	Left_Circular_32(i, s)	(((i) << (s)) | ((i) >> (32-(s))))
	
	// generate the _forward_reference
	int oldestTokenSteppedLength = (shift * (HonestyChecker::MinRunSize - 1)) % 32;
	for (const auto& text: _texts) {
		uint32_t hashValue = 0;
		for (size_t pos = text.begin(); pos < text.end(); ++pos) {
			if (pos - text.begin() + 1 > HonestyChecker::MinRunSize) {
				int oldestTokenValue = _vector[pos - HonestyChecker::MinRunSize].toInt();
				hashValue ^= Left_Circular_32(oldestTokenValue, oldestTokenSteppedLength);
			}
			hashValue = Left_Circular_32(hashValue, shift);
			hashValue ^= _vector[pos].toInt();

			if (pos - text.begin() + 1 < HonestyChecker::MinRunSize) {
				continue;
			}

			size_t runStartPos = pos - HonestyChecker::MinRunSize + 1;

			size_t hashTableSlotPos = hashValue % _hash_table_size;
			if (_latest_index[hashTableSlotPos]) {
				_forward_reference[_latest_index[hashTableSlotPos]] = runStartPos;
			}
			_latest_index[hashTableSlotPos] = runStartPos;
		}
	}

	// optimize the _forward_reference
	for (size_t i = 0; i + HonestyChecker::MinRunSize < _vector_length; ++i) {
		size_t j = _forward_reference[i];

		while (j && !isEqualMinRun(i, j)) {
			j = _forward_reference[j];
		}
		_forward_reference[i] = j;
	}

	return _forward_reference;
}

const size_t* ForwardRefMaker::result() const {
	return _forward_reference;
}

