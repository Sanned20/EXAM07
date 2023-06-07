FROM ubuntu:18.04

RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone
RUN apt-get update

RUN apt-get install qt5-default -y
RUN apt-get install qtbase5-dev -y
RUN apt-get install qt5-qmake
RUN apt-get install build-essential -y

RUN mkdir <ryvkin>
COPY *.cpp /<ryvkin>
COPY *.h /<ryvkin>
COPY *.pro /<ryvkin>

RUN qmake <qt_project>.pro
RUN make