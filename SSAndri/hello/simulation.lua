generateDoor = function(n)
    random = Random()
    ndoors = random:integer(n)
    return random:integer(10)
end

for x=1, 10 do
    print(generateDoor())
end