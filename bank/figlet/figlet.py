from pyfiglet import Figlet

figlet = Figlet()
figlet.getFonts()


if len(sys.argv) == 0:
        text = input ("Input: ")
        figlet.setFont(font=sys.argv[1])
        print(figlet.renderText(text))

else:
         sys.exit("Invalid usage")