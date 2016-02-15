function y=logistic(r,x0)
x=zeros(1,100);
y=zeros(1,100);
y(1)=x0;

    for i=2:100
        y(i)=r*y(i-1)*(1-y(i-1));
        x(i)=i;
    end
    plot(x,y);
    title(['r=', num2str(r, '%3.2f')]);
   
end