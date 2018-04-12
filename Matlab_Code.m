    
clear all
s = serial('COM5','BAUD',9600)
 
fopen(s)


joy = vrjoystick(1);

i = 0;

stopasync(s)

while true
    
        
  
    p = axis(joy);
    
    
    xaxis = p(4);
    yaxis = -p(5);
    
    
    plot(xaxis,yaxis,'+');
    axis([-1 1 -1 1])
    pause(.01)

    
    
    val1 = round(interp1([0,1],[100,1],abs(xaxis)));
    if abs(xaxis) < .15 
        
        val1 = 0;
   
    elseif xaxis < 0
        val1 = val1*-1;
    end
    
    val1 = num2str(val1);
    
        
    val2 = round(interp1([0,1],[100,1],abs(yaxis)));
   
   
    if abs(yaxis) < .15
        val2 = 0;
    elseif yaxis < 0
        val2 = val2*-1;
    end
    
   val2 = num2str(val2);

   
   val = ['x',val1,'y',val2];
   
   if rem(i,5) == 0
   
   fprintf(s,val);
   
   val
   
    
   end
   
   i = i + 1;
    
   
end

 


