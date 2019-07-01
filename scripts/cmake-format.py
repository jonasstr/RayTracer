inFile = "CMakeLists.txt"
mainCpp = "main.cpp"

def start():
    lines = open(inFile, 'r').readlines()
    startLine = -1
    executablesList = []
    with open(inFile, 'r') as input:
        currentLine = 1
        for line in input:
            if 'add_executable(' in line:
                # Found string
                startLine = currentLine
                while currentLine < len(lines) and ')' not in lines[currentLine]:
                    if mainCpp not in lines[currentLine]:
                        executablesList.append(lines[currentLine])
                    currentLine += 1
            else: currentLine += 1
    executablesList.sort()

    with open(inFile, 'w+') as output:
        currentLine = startLine
        while currentLine < len(output):
        for line in lines:
            if line not in executablesList:
                print(line)
                output.write(line)


if __name__ == "__main__":
    start()