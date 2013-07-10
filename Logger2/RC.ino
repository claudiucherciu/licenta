void read_RC(unsigned int &s1, unsigned int &s2, unsigned int &s3) {
  
  
  if (s1 == 0 )
    s1 = pulseIn(9,HIGH, 28000);
  if (s2 == 0 )
    s2 = pulseIn(8,HIGH, 28000);
  if (s3 == 0 )
    s3 = pulseIn(7,HIGH, 28000);
  
  
}
