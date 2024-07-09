def allocate_token(keywords):
    result = dict()
    counts = dict()
    for keyword in keywords:
        first_letter = keyword[0]
        count = counts.get(first_letter, 0)
        
        if count == 0:
            token = f"NORM('{first_letter}')"
        elif count == 1:
            token = f"NORM('{first_letter.upper()}')"
        elif count == 2:
            token = f"CTRL('{first_letter.upper()}')"
        elif count == 3:
            token = f"META('{first_letter}')"
        elif count == 4:
            token = f"META('{first_letter.upper()}')"
        elif count == 5:
            token = f"MTCT('{first_letter.upper()}')"
        else:
            raise Exception("Can't allocate more token for '{keyword}'")
            
        result[keyword] = token
        counts[first_letter] = count + 1
        
    return result

counts = dict()
with open("keywords.txt", "r") as f:
    keywords = f.readlines()
    keywords = map(lambda key: key.rstrip().lower(), keywords)

default_space = 16
keyword_token_pair = allocate_token(keywords)

with open("keywords_list.txt", "w") as f:

    print("static const struct idf reserved[] = {", file=f)
    for keyword, token in keyword_token_pair.items():
        part = f'"{keyword}",'
        output_prefix = " " * 4 + '{' + part + " " * (default_space - len(part))
        print(output_prefix + token + "},", file=f)
    print("};\n", file=f)
    
    print("static const Token Non_Finals[] = {", file=f)
    for keyword, token in keyword_token_pair.items():
        print(" " * 4 + token + "," + " " * 12 + f"/* {keyword} */", file=f)
    print("};", file=f)