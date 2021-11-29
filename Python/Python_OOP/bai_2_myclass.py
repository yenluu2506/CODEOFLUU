class myclass:
    number = 0
    name = 'noname'
def main():
    me = myclass()
    me.number = 1234
    me.name = 'YenLuu'

    print(me.name + ' ' + str(me.number))
if __name__ == '__main__':
    main()