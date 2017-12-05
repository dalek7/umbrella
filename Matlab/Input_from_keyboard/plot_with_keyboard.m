t = 0:0.01:10000;
y = sin(2*pi*1*t);

global index_s;
global index_e;
global dpw; % data points per window
global yData xData;
global windowData;

dpw = 120;
index_s = 1;
index_e = index_s + dpw;

yData = y; 
xData = t;
windowData = yData(index_s:index_e);

fig1 = figure(1);
set(fig1, 'KeyPressFcn', 'key_callback');

plot(t,y);
fig1_axis = get(fig1, 'CurrentAxes');
set(fig1_axis,'xlim',[xData(index_s), xData(index_e)]);


 
