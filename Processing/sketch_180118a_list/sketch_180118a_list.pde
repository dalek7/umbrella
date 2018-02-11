
  
IntList vValue;
StringList vTime;
int cntTmp;
void setup() {
  size(500, 500);
  vValue = new IntList();
  vTime = new StringList();
  cntTmp = 0;
}

void draw() {
  background(204);
  fill(0);   
  String buf = String.format("%d -> buffer size %d", cntTmp, vValue.size());
  
  //String buf = String.format("Hello %06d", frameCount);
  text(buf ,10,50);
  
}

void mousePressed() {
  //save("screen.jpg");
  vValue.append(cntTmp);
  
  String strTime = String.format("%02d%02d%02d_%02d%02d%02d", year(),  month(), day(), hour(), minute(), second()); 
  vTime.append(strTime);
  
  cntTmp++;
  
  println("hello...");
}

void SaveToFile()
{
  int N = vValue.size();
  
  if(N > 0)
  {
    String dataName = String.format("Data_%02d_%02d_%02d_%02d_%02d_%02d.txt", year(),  month(), day(), hour(), minute(), second()); 
    //println("Saving "+ dataName);
    
    PrintWriter output;

    output = createWriter(dataName);
    for(int ii=0; ii<N; ii++)
    {
      String out = String.format("%s\t%d", vTime.get(ii), vValue.get(ii));
      output.println(out);
    }
    output.flush();
    output.close();
    vValue.clear();
    vTime.clear();
    String buf = String.format("Written %d samples", N); 
    println(dataName);
    println(buf);
  }
}


void keyPressed() {
  
  switch(key)
  {
  case 'r':
      println("Reset");
      vTime.clear();
      vValue.clear();
      
      break;
      
  case 's':
      
      SaveToFile();
      break;
      
      
  default:
    break;
  }
}