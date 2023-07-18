function area
clf
x=[7.0  10.5  13.0  17.5  34.0  40.5  44.5  48.0  56.0 ...
    61.0  68.5  76.5  80.5  91.0  96.0 101.0 104.0 106.5 ...
	111.5 118.0 123.5 136.5 142.0 146.0 150.0 157.0 158.0];
y1=[44    45    47    50    50    38    30    30    34 ...
        36    34    41    45    46    43    37    33    28 ...
        32    65    55    54    52    50    66    66    68];
y2=[44    59    70    72    93   100   110   110   110 ...
        117   118   116   118   118   121   124   121   121 ...
        121   122   116    83    81    82    86    85    68];

figure(1)
hold on;
plot(x,y1,x,y2);
stem(x,y1);
stem(x,y2);
hold off;

z1=(trapz(x,y2) - trapz(x,y1))*40*40/18/18
