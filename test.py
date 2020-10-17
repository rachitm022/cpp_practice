# Write function with name remove_first_alphabet which takes a list of string
# Remove first letter from each string and return the list
def remove_first_alphabet(li):
	ans = []
	for str in li:
		str = str[1:]
		ans.append(str)
		
	return ans

# Do not change anything below this line
if __name__ == "__main__":
    alpha = [i for i in input().split(' ')]
    removed_list = remove_first_alphabet(alpha)
    [print(i) for i in removed_list]