function y=prbg(key1,key2,length)

while(key1 >= 1)
    key1=key1/10;
end
while(key2 >= 1)
    key2=key2/10;
end
r1=3.88+10^(-2)*key1;
r2=3.88+10^(-2)*key2;
y1=zeros(1,2);
y2=zeros(1,2);
y1(2)=0.5+10^(-1)*key1;
y2(2)=0.5+10^(-1)*key2;
y=zeros(1,length);
for i=1:(length-1)
    y1(mod(i+1,2)+1)=r1*y1(mod(i,2)+1)*(1-y1(mod(i,2)+1));
    y2(mod(i+1,2)+1)=r2*y2(mod(i,2)+1)*(1-y2(mod(i,2)+1));
    if(y1(mod(i+1,2)+1)>y2(mod(i+1,2)+1))
        y(i+1)=1;
    else
        y(i+1)=0;
    end
end
end
        