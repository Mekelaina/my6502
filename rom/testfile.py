

signature = [0x4D, 0x59, 0x36, 0x35, 0x30, 0x32, 0xFF, 0xFF]

reset_low  = 0xFFFC
reset_high = 0xFFFD

lowbyte = 0x00

highbyte = 0x80

content = []
content += signature
print(content)

for x in range(65536):
    #print(x)
    if x == reset_low:
        content.append(lowbyte)
    elif x == reset_high:
        content.append(highbyte)
    else:
        content.append(0x00)

with open("testrom.my6502", "wb") as file:
    c = bytearray(content)
    file.write(c)