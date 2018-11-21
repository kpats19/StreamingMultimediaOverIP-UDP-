# StreamingMultimediaOverIP-UDP-


Multimedia over IP 

This project will expose you to streaming multimedia and the fundamentals of voice/video-over-IP. In this project you will implement a simple UDP packet radio transmitter (called udp). This program will run as follows:

$ udp host port filename p1 p2 p3

As demonstrated in class, your packet radio transmitter will packetize an audio file (which is provided) into UDP packets and transmit the packets to the host:port. (This packet radio transmitter is about 30 lines of C, probably fewer in Java. Note that you can't use external libraries of any sort in Java.) You will test your radio transmitter on the two files we saw in class (both MP3). For each audio file you will assign a quality rating (1-10, 10=best) and plot the results on a graph as discussed in class. The parameters p1, p2, p3 can represent anything you want e.g. the packet size, the transmission delay, buffer size etc. You need not use all 3 parameters but your program should accept max 3 parameters.


Next you will use the open source multimedia tool ffmpeg to convert the MP3 to a (semi) lossless format such as WAV or PCM/MULAW and again run your program and plot the results on the same graph. As you perform the tests try to think of the three or four factors that affect how the audio is delivered, received and played. These factors include audio encoding, jitter, delayed/out-of-order packets, and timing (e.g. real-time: can users tune out and tune back in later). Think about how you will handle video. Though this is an open-ended assignment, you should follow these general requirements:
(1) Start by reading Chapter 8 (UDP sockets) of the UNP (Stevens) book. Also look at the link here. The programming part is a straightforward graft of the UDP client/server. Note – you can also use Java (with the same restrictions as before). Start early!!
(2) Your packet radio must transmit a UDP packet stream and VLC is the listener. (If your laptop cannot handle VLC because of firewalls you can download and use VLC in the Student Mall Lab PCs.) You will be provided with 2 MP3 files which we will use to test your radio.
(3) It’s not about programming this time, rather it is about how UDP packets are handled. (By which I mean the non-programmers can roll up your sleeves and do netstat / Wireshark to help the team.)
