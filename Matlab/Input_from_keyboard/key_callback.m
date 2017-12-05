function key_callback

global index_s;
global index_e;
global dpw;
global xData yData;
global windowData;

key = get(gcbf, 'CurrentCharacter');
disp(key);

switch key
    case 'a' 
        if(index_e < length(yData) -  dpw)
            index_s = index_e;
            index_e = index_s + dpw;
        end
    case 's'
        if(index_s > dpw)
            index_e = index_s;
            index_s = index_e - dpw;
        end
end

windowData = yData(index_s:index_e);

fig1_axis = get(gcbf, 'CurrentAxes');
set(fig1_axis,'xlim',[xData(index_s), xData(index_e)]);
end