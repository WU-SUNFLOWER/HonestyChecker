import sys
import os
import platform
import re

is_windows = platform.system() == 'Windows'
cwd = os.getcwd()

check_pattern = re.compile(r'\\tools\\?$' if is_windows else r'/tools/?$')
changed_dir = '../' if re.search(check_pattern, cwd) else ''

sys.path.append(os.path.join(cwd, changed_dir + 'dist'))

from libHonestyChecker import compare

old_texts = []

with open(changed_dir + 'test_case/1_a.txt', 'r', encoding='utf-8') as f:
    new_text = f.read()

with open(changed_dir + 'test_case/1_b.txt', 'r', encoding='utf-8') as f:
    old_texts.append(f.read())

with open(changed_dir + 'test_case/1_c.txt', 'r', encoding='utf-8') as f:
    old_texts.append(f.read())

print(compare('C++', new_text, old_texts))
