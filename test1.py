# your code goes here
n = int(input())
for _ in range(n):
	a = input().split(' ')
	b = input().split(' ')
	carry = 0
	ans = ""
	for i in range(max(len(a),len(b))):
		if i>=len(a):
			tmp = int(b[i])+carry
			ans+=str(tmp%10)
			carry = tmp//10
		elif i>=len(b):
			tmp = int(a[i])+carry
			ans+=str(tmp%10)
			carry = tmp//10
		else:
			tmp = int(a[i])+int(b[i])+carry
			ans+=str(tmp%10)
			carry = tmp//10
	
	if carry>0:
		ans+=str(carry)
		
	print(ans)