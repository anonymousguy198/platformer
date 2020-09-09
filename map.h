struct MAP{
    char mapdata[20][20];      //update your header file >:(
};


struct MAP LoadMap(void);   //return type was void

void RenderMap(struct MAP map,int cellx,int celly);  //<- missed a semicolon here. Reason for all that error

// Dont make functions extern
