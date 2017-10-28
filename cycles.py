wholeString = input() 
shifter = ""
stringList = []
stringSize = ""
stringShift = ""
shift = 0
size = 0
z = 0
for x in wholeString:
	if z == 0:
		stringSize += x
	if z == 1:
		stringList.append(x)
	if z == 2:
		stringShift+= x
	if x == " ":
		z += 1
size = int(stringSize)
shift = int(stringShift)
stringList.pop(size)
for i in range(size):
	for i in range(shift):
		shifter = stringList[0]
		stringList.pop(0)
		stringList.insert(size,shifter)
	result = ""
	for x in stringList:
		result += x
	print(result)