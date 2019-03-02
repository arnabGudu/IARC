void follow()
{
  float frontPing = Ping(FRONT);
  float rightPing = Ping(RIGHT);
  //float leftPing  = Ping(LEFT);

  if (node == RIGHT)
  {
    if (frontPing > dist[FRONT] && rightPing < dist[RIGHT])
    {
      pid();            //if no obstacle infront and wall on side then follow wall with pid
    }
    else if (frontPing > dist[FRONT] && rightPing > dist[RIGHT])
    {
      right();          //if no obstacle infront and no wall then turn right
      delay(del);
    }
    else
    {
      left();           //if obstacle infront then turn left
      delay(del);
    }
  }
  else
  {
    if (frontPing > dist[FRONT] && rightPing < dist[RIGHT])
    {
      pid();            //if no obstacle infront and wall on side then follow wall with pid
    }
    else if (frontPing > dist[FRONT] && rightPing > dist[RIGHT])
    {
      right();          //if no obstacle infront and no wall then turn right
      delay(del);
    }
    else
    {
      left();           //if obstacle infront then turn left
      delay(del);
    }    
  }

  //print general details
  if (flag == 1)
    Print();
}
