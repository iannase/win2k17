wholeString = input()

sizeString = ""
size = 0
z = 0
y = 0
encryptedNumberString = ""
negative = False
binarySize = 0
numZeros = 0
encryptedString = ""

encryptedNumberStrings = []
encryptedNumberInts = []
encryptedNumberBinaries = []
decryptedNumberBinaries =[]
decryptedNumberInts =[]
encryptedNumberFullBinary =[]
trueBinariesList = []
trueBinary = []
negativeList = []
encryptedNumberBinariesDos = []

wholeStringList = []
otherWholeStringList = []

for x in wholeString:
	wholeStringList.append(x)
	otherWholeStringList.append(x)

for x in wholeStringList:
	if z == 0:
		sizeString += x
		otherWholeStringList.pop(0)
	if x == " ":
		z+=1
		break

for x in otherWholeStringList:
	if x != " ":
		encryptedNumberString += x
	if x == " ":
		encryptedNumberStrings.append(encryptedNumberString)
		encryptedNumberString = ""
encryptedNumberStrings.append(encryptedNumberString)

for x in encryptedNumberStrings:
	encryptedNumberInts.append(int(x))

for x in encryptedNumberInts: 
	if x < 0:
		negativeList.append(True)
	if x > 0:
		negativeList.append(False)

print(encryptedNumberInts)

for x in encryptedNumberInts:
	encryptedNumberBinaries.append(bin(x))
	encryptedNumberBinariesDos.append(bin(x))

for zz in range(len(encryptedNumberBinaries)):
	z = 1
	if negativeList[zz]:
		for x in encryptedNumberBinariesDos:
			if z > 3:
				encryptedString+=x
			z+=1
		encryptedNumberBinariesDos[zz] = encryptedString

	z = 1
	if negativeList[zz] == False:
		for x in encryptedNumberBinariesDos:
			if z > 2:
				encryptedString+=encryptedNumberBinariesDos[x]
			z+=1
		encryptedNumberBinariesDos[zz] = encryptedString

for x in range(len(encryptedNumberBinariesDos)):
	binarySize = len(encryptedNumberBinariesDos[x])
	numZeros = 31 - binarySize

	if x[0] == "-":
		trueBinary.append("1")
		negative = True

	if x[0] == "0":
		trueBinary.append("0")
		negative =  False

	for i in range(numZeros):
		trueBinary.append("0")

	for i in range(binarySize):
		trueBinary.append(encryptedNumberBinariesDos[i])

	print(trueBinary)
	trueBinary = []










