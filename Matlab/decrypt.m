function y=decrypt(ciphertext,key)
ciphervec=cast(ciphertext,'int32');


%begin key division in 2 keys
key_vector= num2str(key) -'0';
key_length=length(key_vector);

if(mod(key_length,2)==0)
    midpoint=key_length/2;
    key1=zeros(1,midpoint);
    key2=zeros(1,midpoint);
    for i=1:midpoint
        key1(i)=key_vector(i);
        key2(i)=key_vector(midpoint+i);
    end
else
    midpoint=(key_length-1)/2;
    key1=zeros(1,midpoint);
    key2=zeros(1,(key_length-midpoint));
    for i=1:midpoint
        key1(i)=key_vector(i);
        key2(i)=key_vector(midpoint+i);
    end
    key2(midpoint+1)=key_vector(key_length);
end

nkey1=0;
nkey2=0;
for i=1:length(key1)
    nkey1=nkey1+key1(length(key1)-i+1)*10^(i-1);
end
for i=1:length(key2)
    nkey2=nkey2+key2(length(key2)-i+1)*10^(i-1);
end
%end key division in two keys
%begin initializing pseudo-random number generator

prnum=zeros(1,length(ciphervec));
vpool=prbg(nkey1,nkey2,8*length(ciphervec));
plaintext=zeros(1,length(ciphervec));
%generated pseudo-random(key) vector pool vpool

for i=1:length(ciphervec)
    prnchar=0;
    for j=0:7
        prnchar=prnchar+2^j*vpool(8*(i-1)+j+1);
    end
    
        plaintext(i)=ciphervec(i)-prnchar-32;
    while(plaintext(i)<32)
        plaintext(i)=plaintext(i)+91;
    end
end

y=cast(plaintext,'char');

end
