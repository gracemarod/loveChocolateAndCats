#!/usr/bin/python

#************************************************************
# flowReader_2.py
# ------------------------
# Grace M. Rodriguez
# May 5, 2015
#************************************************************
#-- flowReader_2.py -----------------------------------------------------------------
# This code reads IPv6 flow data from a file with fileinput and converts the address
# in coordinates of range 0 to 1.
#
#------------------------------------------------------------------------------------
import fileinput
import math

# /****************************************************************
# Method : readFile()
# Use    : Reads the data from the file written in the command line
#		   and saves it in the list "data".
# Input  : none
# Return : data
# *****************************************************************/
def readFile():
	data = []
	for line in fileinput.input():
		line = line.strip()
		fields = line.split("|")
		fields = [field.strip() for field in fields]
		data.append(fields)
	return data

data = readFile()

# /****************************************************************
# Method : countColons()
# Use    : Takes the address and splits into elements in each colon(:) 
#		   found. Afterwards, it adds 0 to all the elements in the list
#		   if found that they're empty.
# Input  : IPadd (IP address)
# Return : IPadd 
# *****************************************************************/
def countColons(IPadd):
	IPadd = IPadd.split(":")
	missing = (8 - len(IPadd)) + 1
	for i in range(0, len(IPadd)):
		if IPadd[i] == "":
			IPadd[i:i+1] = ["0"] * missing
 		if IPadd[-1] == "":
 			IPadd[-1] = "0"
	return IPadd

# /****************************************************************
# Method : poly()
# Use    : It multiplies each element in the list with 2**16, and 
#		   adds each element together with the index "coeff" in base 
#		   16. This is to convert the string to int.
# Input  : s (list with blocks of the addresses)
# Return : result
# *****************************************************************/
def poly(s):
	result = 0
	for coeff in s:
		result *= 2**16
		result += int(coeff,16)

	return result


# /****************************************************************
# Method : ipv6ToInt()
# Use    : This is used to unite the result of the address after the
#		   neccessary 0 are added and convert it to an int.
# Input  : s 
# Return : poly()
# *****************************************************************/
def ipv6ToInt(s):
	return poly(countColons(s))

exp128 = 2**128
exp16 = 2**16

#In the list of flow data that we have, we use record[0], which is the 
#IP Source Address and record[1] which is the IP Destination Address
#for the dPort, we only have to divide it with 2**16.
for record in data[1:]:
	print   1.0*ipv6ToInt(record[0])/exp128,1.0*ipv6ToInt(record[1])/exp128,float(record[3])/exp16 








