function   z=harmonic(p)
total=0;
subtotal=0;
n=0;
z=[];
for k = 1:p
    while subtotal<1/2
        n=n+1;
        subtotal=subtotal+1/n;
    end
    total=total+subtotal;
    subtotal=0;
    z=[z;n,total];
end