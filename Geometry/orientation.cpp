// line p1--->p2,,point p3
// Or, p1->p2->p3 orientation
int orientation(pair<int,int>&p1,pair<int,int>&p2,pair<int,int>&p3){
	int val=(p2.ff-p1.ff)*(p3.ss-p1.ss)-(p2.ss-p1.ss)*(p3.ff-p1.ff);
	if (val==0) return 0; // p3 on line Or collinear
	if (val<0) return -1; // p3 on right side Or anti-clockwise turn
	if (val>0) return 1; // p3 on left side Or clockwise turn
}