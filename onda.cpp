#include<iostream>
#include<math.h>

using namespace std;

int find_t(double ** y, double t, int Nt, int m);
int main()
{
  double c=0.1;
  int Nx=200;
  int Nt=6000;
  double dx=1.0/Nx;
  int maximo=Nx/4;
  double dt=dx/c;
  double * u_initial = new double[Nx];
  double * u= new double[Nx];
  int * tiempos= new int[4];
  double pi=acos(-1);
  double x=0.0;
  for(int i=0;i<Nx;i++)
  {
    x+=dx;
    u_initial[i]=sin(x*2*pi);
  }
  double ** u_save = new double*[Nt];
  for(int i=0;i<Nt;i++)
  {
    u_save[i]=new double[Nx];
  }
  double * u_first=new double[Nx];
  for(int i=1;i<Nx-1;i++)
  {
    u_first[i]=u_initial[i]+( (c*c*dt*dt)/( 2.0*dx*dx ) * ( u_initial[i+1] + u_initial[i-1] - ( 2.0 * u_initial[i] ) ) );
  }
  for(int i=0;i<Nx;i++)
  {
    u_save[0][i]=u_initial[i];
    u_save[1][i]=u_first[i];
  }
  bool centinela=false;
  int j=2;
  while(!centinela)
  {
    for(int i=1;i<Nx-1;i++)
    {
      u[i]=(2.0*u_first[i])-u_initial[i]+ ( ( (c*c*dt*dt)/(dx*dx) ) * ( u_first[i+1] + u_first[i-1] - (2.0 * u_first[i]) ) );
    }
    for(int i=1;i<Nx-1;i++)
    {
      u_initial[i]=u_first[i];
      u_first[i]=u[i];
      u_save[j][i]=u[i];
    }
    j++;
    if(u[maximo]==-1)
    {
      centinela=true;
    }
  }
  x=0.0;
  cout<<find_t(u_save,1.0,Nt,maximo)<<endl;
  /*
  for(int j=0;j<Nt;j++)
  {}
    for(int i=0;i<Nx;i++)
    {
      x+=dx;
      cout<<u_save[j][i]<<" ";
    }
    cout<<endl;
  }*/
  return 0;
}
int find_t(double ** y, double t, int Nt, int m)
{
  int tiempo;
  int j=0;
  bool centinela=false;
  while(!centinela)
  {
      if(y[j][m]==t)
      {
        tiempo=j;
        centinela=true;
      }
      if(j==(Nt-1))
      {
        centinela=true;
      }
      j++;
  }
  return tiempo;
}
