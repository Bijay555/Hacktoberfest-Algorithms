#commit by Suyash
def linearsearch(char_list, findChar):
	for i in range(len(char_list)):
		if char_list[i] == findChar:	#checking if element exixts or not
			return i+1
	return -1
character=input("Enter numbers/characters/words separated by space: ")
character_list=character.split()
print(character_list)
find_char=input("Enter number/character/word to search: ")
flag=linearsearch(character_list,find_char)
if(flag==-1):
	print("Character not present!")
else:
	print("Character found at position "+str(flag))
