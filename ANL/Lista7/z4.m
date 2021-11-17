function w=z4(n)
  h=2/n;
  x=-1:h:1;
  k=length(x);
  t=-1:0.01:1;
  f=(t-x(1));
  for i = 2:k
    f=f.*(t-x(i));
  endfor
  g=cos((n+1)*acos(t))/2^n;
  plot(t,f,t,g);
  w=max(abs(f))/max(abs(g));
  endfunction
