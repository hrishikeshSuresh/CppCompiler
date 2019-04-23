lines =[]
with open('output/icg_output.txt','r') as file:
    for line in file:
        lines.append(line.strip())
print(lines)
new_lines = []
for line in lines:
	if line !="\n" and line!='':
		new_lines.append(line.strip())
print(new_lines)

text_file = open("output/optimized_output.txt", "w")
for line in new_lines:
	text_file.write(line)
	text_file.write('\n')
text_file.close()




