FROM ubuntu:18.04

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update

RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

RUN mkdir ryvkin_221-3210
COPY *.cpp /ryvkin_221-3210
COPY *.h /ryvkin_221-3210
COPY *.pro /ryvkin_221-3210
COPY echoServer.pro /ryvkin_221-3210

RUN qmake echoServer.pro
RUN make