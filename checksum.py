def checksum(data):
    sum = 0
    for char in data:
        sum += char
        print(sum)
    return  bin((sum%256))

data = [0xFE, 0x05, 0x03, 0x1E, 0x00, 0x00]
print(checksum(data))