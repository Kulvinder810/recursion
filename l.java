public class l{
    Boolean [] r=new Boolean [4];
    Boolean [] c=new Boolean [4];
    Boolean [] dig=new Boolean [r.length+c.length+1];
    Boolean [] antidig=new Boolean [r.length+c.length+1];

    public static Boolean isQueenSafe(Boolean[][]boxes,int x,int y){ 
        if(r[x]==true||c[y]==true||dig[x+y]==true||antidig[x-y+antidig.length])
    return false;
        return true;

    }
    public static int queens2D(Boolean[][] boxes,int lqpl,int tnq,int qpsf,String s){
        if(qpsf==tnq){
            System.out.println(s);
            return 1;
        }
        int count=0;
        for(int i=lqpl;i<boxes.length*boxes[0].length;i++){
            int x=i/boxes[0].length;
            int y=i%boxes[0].length;
            if(isQueenSafe(boxes,x,y)){
                boxes[x][y]=true;
            count+=queens2D(boxes,i+1,tnq,qpsf+1,s+"( "+x+" "+y+") "); 
                boxes[x][y]=false;
            }
        }
        return count;
    }
    public static void main(String[] args){
        Boolean[][] ar=new Boolean[4][4];
        System.out.println(queens2D(ar,0,4,0,""));

    }
}