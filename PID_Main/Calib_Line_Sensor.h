void queophainhe()
{
    vtt = 80;
    vtp = 100;
}

void queotrainhe()
{
    vtt = 100;
    vtp = 80;
}

void chaythangbasespeed()//bam line
{
    vtt = 100;
    vtp = 100;
}

void caliblinesensor(){
  if (c == 1){
    chaythangbasespeed();
  }
  
  if (b == 1) {
    queophainhe();
  }

  if (d==1){
    queotrainhe();
  }
}

void chaythangfullspeed(){
  
}
