function PlayMusicFile(str)
     if ~exist(str,'file')
         error("Inexist File Path:%s",str);
     end
    script=fopen(str,"rt");
    key_mat=fscanf(script,"%c %d Fs=%d\n",[1,3]);
    scr=fscanf(script,"%d %d %d %f\n",[4,inf]);
    fclose(script);

    Fs=key_mat(3);
    T0=60/key_mat(2); %节拍
    key=char(key_mat(1));

    scr_note=scr(1,:);
    scr_noct=scr(2,:);
    scr_risg=scr(3,:);
    scr_dur=scr(4,:);
    len=1:length(scr_note);
    Y=[];

    for i=len
        note=[scr_note(i),scr_noct(i),scr_risg(i),scr_dur(i)*T0];
        wfm2=SoundNote(key,note,Fs);
        Y=[Y,wfm2];
    end
    sound(Y,Fs);
end