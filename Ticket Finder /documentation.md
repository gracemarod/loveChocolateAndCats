#ticketParser.py
Creator: Grace M. Rodríguez Gómez
April 21, 2015

Overview:
The script first checks if the command line has four arguments including the code file. If they are four, then the function correctArguments() will check if the arguments were written correctly. The accepted arguments are OK, WARNING or UKNOWN for state, SOFT or HARD for statetype and the host. If none of these options are found, then it will display an error and exit.

The function readFile() opens the file hostsTickets.txt and saves the data in the dictionary d. The built-in function split() is used to separate the host and ticket and save them as key = host and value = ticke.

If the state is OK, readArg() will check if the host is a key in the dictionary. If it is, it will delete it. The file will be opened again and the remaining keys and values will be written in the file. When the state is WARNING and the statetype HARD, readArg() will look again if the host is in d. If it is, it will display it and break from the loop. If it found that the host it’s not in d, it will open the file again and append the host. The last ticket is search in the dictionary to split it and convert its numbers to an int. That way it can be incremented so it creates a new ticket for the new host.

Reference:

Starting out with Python 2nd Edition by Tony Gaddis

[http://www.tutorialspoint.com/python](http://www.tutorialspoint.com/python)

[https://docs.python.org](https://docs.python.org)

[http://www.tutorialspoint.com/python](http://www.tutorialspoint.com/python)
