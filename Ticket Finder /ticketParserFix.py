#!/usr/bin/python
#************************************************************
# ticketParser.py
# ------------------------
# Grace M. Rodriguez
# April 21, 2015
#************************************************************
#-- ticketParser.py ------------------------------------------------------------------
# This code takes command line arguments and passes it to the script as strings.
#
#-------------------------------------------------------------------------------------
import sys
import collections 

# main function
def main():

	usage()

	STATE=sys.argv[1]
	STATETYPE=sys.argv[2]
	HOST=sys.argv[3]

	correctArguments(STATE,STATETYPE,HOST)

	d = readFile()

	check = readArg(STATE,STATETYPE,HOST,d)

	if not check:
		print "Data remained the same. \n"

	printOutput(d)

# /****************************************************************
# Method : usage()
# Use    : Checks if they're 4 arguments in the command line
#		   including the Python script
# Input  : none
# Return : none
# *****************************************************************/
def usage():
	correctArg = True

	if len(sys.argv) != 4:
		print "Incorrect format. "
		print "<filename> <STATE:OK, WARNING or UNKNOWN> <STATETYPE:HARD or SOFT> <HOST> "
		exit()
	return

# /****************************************************************
# Method : readFile()
# Use    : Reads data in file, splits host and ticket and saves it
#		   in the dictionary d as key=host and value=ticket.  
# Input  : none
# Return : d 
# *****************************************************************/
def readFile():
	f = open('hostsTickets.txt','r')
	d = collections.OrderedDict()
	for line in f:
		data = line.replace("\n", "")
		data = data.split(":")
		host = data[0]
		ticket = data[1]

		#saving variables to dictionary
		d[host] = ticket
	f.close()
	return d

#Split the elements in to two elements when : is found
# /****************************************************************
# Method : correctArguments()
# Use    : Checks if the arguments written in the command line
#		   were written correctly.
# Input  : State, Statetype and Host
# Return : none
# *****************************************************************/
def correctArguments(STATE,STATETYPE,HOST):
	boolArg = False

	if STATETYPE in ("HARD", "SOFT") and STATE in ("OK", "WARNING", "UNKNOWN") and "host" in HOST:
		boolArg = True

	if not boolArg:
		print "Incorrect format. "
		print "<filename> <STATE:OK, WARNING or UNKNOWN> <STATETYPE:HARD or SOFT> <host#> "
		exit()


#Checks if the arguments were written correctly
# /****************************************************************
# Method : readArg()
# Use    : Writes or deletes data in the file depending on the
#		   arguments written.
# Input  : State, Statetype and Host
# Return : boolean check
# *****************************************************************/
def readArg(STATE,STATETYPE,HOST, d):
	check = False
	if(STATE in ("OK")):
	 	if HOST in d: 
	 		print HOST + " and " + d[HOST] + " have been recovered. " + "\n"
	 		del d[HOST]
	 		newFile = open("hostsTickets.txt", "w")
			for keys,values in d.items():
				newData = keys + ":" + values + "\n"
				newFile.write(newData) 
			newFile.close()
			check = True		

	elif (STATE in ("WARNING")): 
		if (STATETYPE in ("HARD")):
			#for whichHost in d.keys():
			if HOST in d: 
				print HOST +" already has a ticket open: " +d[HOST] + "\n"
				check = True

			if not check: 
				tickValue = d.values()[-1]
				tickValue = tickValue.split("K")
				tickNum = int(tickValue[1])
				newNum = tickNum + 1
				newTick = "TICK0" + str(newNum)
				d[HOST] = newTick
				newData = HOST + ":" + newTick
				newFile = open("hostsTickets.txt", "a")
				newFile.write(newData + "\n")
				print "The ticket " +newTick +" has been created for " + HOST + "\n"
				check = True
				newFile.close()

	else: #unknown
		if HOST in d: 
			print HOST +" already has a ticket open: " +d[HOST] + "\n"
	return check

# /****************************************************************
# Method : printOutput()
# Use    : Prints the remaining data.
# Input  : none
# Return : none
# *****************************************************************/
def printOutput(d):
	print "Data currently on file:"
	for key, values in d.items():
	 	print key +":" +values

main()
