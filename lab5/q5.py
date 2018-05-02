action_table = {'S0': {'i': 'S3'},
				'S1': {'$': '@'},
				'S2': {'+': 'S4', '$':'R2'},
				'S3': {'+': 'R3', '$':'R3'},
				'S4': {'i':'S3'},
				'S5': {'$':'R1'}
				}
goto_table = {'S0': {'E':'S1', 'T':'S2'},
				'S1': {},
				'S2': {},
				'S3': {},
				'S4': {'E':'S5', 'T':'S2'},
				'S5': {}
				}

print "Enter your string: "
inp = raw_input()
inp += '$'
stack = [('dummy', 'S0')]

j = 0

while True:
	print "input read: ", inp[j]
	if inp[j] in action_table[stack[-1][1]]:
		act = action_table[stack[-1][1]][inp[j]]
		if act == '@':
			print "*****************Accepted\n"
			break
		elif act[0] == 'S':
			stack.append((inp[j], act))
			print "Shift: ", act
			j += 1
		elif act[0] == 'R':
			if act == 'R0':
				stack.pop()
				stack.append(('S', goto_table[stack[-1][1]]['S']))
				print "Reduction: S -> E"
			elif act == 'R1':
				stack.pop()
				stack.pop()
				stack.pop()
				stack.append(('E', goto_table[stack[-1][1]]['E']))
				print "Reduction: E -> T+E"
			elif act == 'R2':
				stack.pop()
				stack.append(('E', goto_table[stack[-1][1]]['E']))
				print "Reduction: E -> T"
			else:
				stack.pop()
				stack.append(('T', goto_table[stack[-1][1]]['T']))
				print "Reduction: T -> i"
		

	else:
		print "****************Error, Not Accepted\n"
		break