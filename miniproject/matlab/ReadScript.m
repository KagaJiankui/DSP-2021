clear;close;clc;
script=fopen("script_tkzc.txt","rt");
key=fscanf(script,"%c %d Fs=%d\n",[1,3]);
scr=fscanf(script,"%d %d %d %f\n",[4,inf]);
fclose(script);