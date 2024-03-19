function wfm2=SoundNote(key,note,Fs)
    % 发出给定调号和音符的音频
    % 语法: wfm=SoundNote(key,note,Fs)
    % key: 调号,字符'A'到'G'
    % note: 音符数组, note=[tone,noctave,rising,duration]
    % tone,noctave,rising遵守 tone2freq()函数的约定
    % duration为持续时间,单位为秒
    % Fs: 抽样频率
    duration=note(4);
    Tv=linspace(0,duration,duration*Fs);
    if note(1)==0
        wfm2=zeros(1,round(duration*Fs));
    else
        fc1=tone2freq(note(1),note(2),note(3),key,0);
        fc1_list=fc1*(1:19);
        amp=[987.8,368.6,620.2,483.9,156.7,83.62,120.1,70.73,5.348,24.41,27.35,21.3,10.31,6.477,15.91,3.495,2.546,0.4751,0.8858]/1000;
%         amp=GenOscAmpl(19,0.21,0.73);
        wfm1=cell2mat(arrayfun(@(a,x) a*sin(2*pi*x*Tv),amp,fc1_list,'UniformOutput',false).');
        wfm1=sum(wfm1,1).*GenADSRenv(wfm1,[0.008,0.09,0.11,0.25,0.67],[0.88,0.88,0.56,0.50,0]);
        [b_b1,a_b1]=butter(6,2*[1300,1900]/Fs);
        [b_b2,a_b2]=butter(6,2*[3600,5000]/Fs);
        [b_b3,a_b3]=butter(6,2*[7800,8200]/Fs);
        wfm2=1.1*wfm1+0.4*filter(b_b1,a_b1,wfm1)+0.35*filter(b_b2,a_b2,wfm1)+0.25*filter(b_b3,a_b3,wfm1);
        wfm2=wfm2/(max(wfm2));
    end
end