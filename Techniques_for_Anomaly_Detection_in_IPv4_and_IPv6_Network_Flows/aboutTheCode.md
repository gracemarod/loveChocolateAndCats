For my research in Searching for anomalies in IPv4 and IPv6 flows, we decided to make a simple program in Python that would read a file with the IPv6 flow data and display the data in a 3d graph. The coordinates for the graph would be the IP Source Address for X, the IP Destination for Y and the Destination (dPort) for Z. The data that was used was the flow data captured from the UPR-RP Network in April 10, 2015.The file is included in the repository. 

The main purpose of this script is to have coordeantes from IPv6 addresses and display them in cube. The output of the program can be easily save in a file and then use in Gnuplot to make a 3d graph. 

Also, since we’re using the library fileinput to process lines from input streams, we have to write the name of the file we want the data read in the command line. For example, for flowReader_2.py the command line would look like this 

$ python flowReader_2.py ipv6Flow.txt

This research is done at the University of Puerto Rico, Rio Piedras Campus. It is supported by the scholarship Academics and Training for the Advancement of Cybersecurity Knowledge in Puerto Rico (ATACK-PR) supported by the National Science Foundation under Grant No. DUE-1438838. The presentation can be found at [http://figshare.com/articles/Techniques_for_Anomaly_Detection_in_IPv4_amp_IPv6_Network_Flows/1424486](Techniques_for_Anomaly_Detection_in_IPv4_amp_IPv6_Network_Flows). 