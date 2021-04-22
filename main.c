#include<windows.h>
#include<math.h>
#define PI 3.14159265358979323846
#include<stdbool.h>
double** randm(int rows, int cols){
                double** matrix = (double**)malloc(rows * sizeof(double*));

                for (int i = 0; i < rows; i++)
                    matrix[i] = (double*)malloc(cols * sizeof(double));

                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        matrix[i][j] =  2.0 * rand()/RAND_MAX;
                    }
                }

                return matrix;
            }

double** mulmr(double coef, double **matrix, int rows, int cols){
                for (int i = 0; i < rows; i++)
                {
                    for (int j = 0; j < cols; j++)
                    {
                        matrix[i][j] = matrix[i][j] * coef;

                        if(matrix[i][j] > 1.0)
                        {
                            matrix[i][j] = 1;
                        } else matrix[i][j] = 0;
                        }
                }

                return matrix;
            }
double** symmetricalMatrix(double **matrix, int r, int c){
             for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                       if (matrix[i][j] == 1) matrix[j][i] = 1;
                }
            }
        return matrix;

        }

double** powgraph(double **matrix, int rows, int col, double **symMatrix) {
int count=0;
int count1=0;
int count2=0;
int total, total1;
 printf("\n\n");
for(int i=0; i<rows; i++){
        count = 0;
    for(int j=0; j<col; j++) {
        if(matrix[i][j]==1) count++;
total=count;
    }
    printf("Pow: %d , def+: %d  ",i+1,count);
     //printf("\n\n");
 count1 = 0;
    for(int j=0; j<rows; j++) {
        if(matrix[j][i]==1) count1++;
        total1=count1;
    }
    printf("Pow: %d , def-: %d  ",i+1,count1);
    if(total==0 && total1==0) {
       printf("Isolated: %d" ,i+1);
        printf("\n\n");
    }
    if((total == 1 && total1 == 0) || (total == 0 && total1 == 1)) {
       printf("Hang: %d" ,i+1);
        printf("\n\n");
    }

}
 printf("\n\n");
for(int i = 0; i<rows;i++){
            count2 = 0;
            for(int j = 0;j<col; j++){
                if(symMatrix[i][j]==1) count2++;
            }
            if(count2 == 1){
                printf("Pow: %d ,Hang, def : %d  ",i+1,count2);
            }else if (count2 == 0){
                printf("Pow: %d ,Isolated, deg : %d  ",i+1,count2);
            }else{
                printf("Pow: %d , def : %d  ",i+1,count2);
            }

        }
}

double **wayslength(double** matrix, int rows, int cols){
printf_s("\n\n");
    printf_s("ways for 2\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                for (int k = 0; k < cols; k++) {
                    if (matrix[j][k] == 1) printf(" %d->%d->%d  ", i+1, j+1, k+1);
                }
            }
        }
        printf_s("\n");
    }
    printf_s("\n\n");
    printf_s("ways for 3\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1) {
                for (int z = 0; z < cols; z++) {
                    if (matrix[j][z] == 1) {
                        for (int y = 0; y < cols; y++) {
                            if (matrix[z][y] == 1) printf(" %d->%d->%d->%d  ", i+1, j+1, z+1, y+1);
                        }
                    }
                }
            }
      }
        printf_s("\n");
    }
}


double **connectionMatrix(double **matrix,int n){
                int reachA[n][n];
                int transponentA[n][n];
                int resMatrix[n][n];
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < n; j++)
                        reachA[i][j] = matrix[i][j];
                for (int k = 0; k < n; k++) {
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            reachA[i][j] = reachA[i][j] || (reachA[i][k] && reachA[k][j]);
                        }
                    }
                }
                printf("Reached matrix \n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {


                            printf ("%d ", reachA[i][j]);
                    }
                    printf("\n");
                }
                printf("Matrix of connection \n");
                for (int i = 0; i < n; i++){
                    for (int j = 0; j < n; j++) {
                        transponentA[i][j] = reachA[j][i];
                            resMatrix[i][j]=reachA[i][j]*transponentA[i][j];
                    }

                }
                 for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ",resMatrix[i][j]);
            }
            printf("\n");
            }
       int count = 0;
       int size;
double **components[]={};

for (int j = 0; j < n; j++)
{
    for (int i = 0; i < n; i++)
    {
        bool found = false;
        for (int k = j+1; k < n; k++)
        {
            if (resMatrix[j][i]==resMatrix[k][i])
            {
                count++;
                found = true;
                break;
            } else break;

        }

        if (found) break;
    }
}
printf("Components amount in group:%d ", count);
}


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//void arrow(float fi, int px,int py);

//объявляем строку-имя программы
char ProgName[]="Лабораторна робота 3";

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
    HWND hWnd;
    MSG lpMsg;

    WNDCLASS w; //создаём экземпляр структуры WNDCLASS

    w.lpszClassName=ProgName; //имя программы - объявлено выше
    w.hInstance=hInstance; //идентификатор текущего приложения
    w.lpfnWndProc=WndProc; //указатель на функцию окна
    w.hCursor=LoadCursor(NULL, IDC_ARROW); //загружаем курсор
    w.hIcon=0; //иконки у нас не будет пока
    w.lpszMenuName=0; //и меню пока не будет
    w.hbrBackground = LTGRAY_BRUSH; //WHITE_BRUSH;// цвет фона окна
    w.style=CS_HREDRAW|CS_VREDRAW; //стиль - перерисовываемое по х и по у
    w.cbClsExtra=0;
    w.cbWndExtra=0;

    if(!RegisterClass(&w))
        return 0;

   // HWND hWnd;
    //MSG lpMsg;

//Создадим окно в памяти, заполнив аргументы CreateWindow
    hWnd=CreateWindow(ProgName, //Имя программы
        "Лабораторна робота 3. Виконала Саніна А. М.", //Заголовок окна
        WS_OVERLAPPEDWINDOW, //Стиль окна - перекрывающееся
        400, //положение окна на экране по х
        100, //положение по у
        960, //ширина
        600, //висота
        (HWND)NULL, //идентификатор родительского окна
        (HMENU)NULL, //идентификатор меню
        (HINSTANCE)hInstance, //идентификатор экземпляра программы
        (HINSTANCE)NULL); //отсутствие дополнительных параметров

//Выводим окно из памяти на экран
    ShowWindow(hWnd, nCmdShow);
//Обновим содержимое окна
 //   UpdateWindow(hWnd);

//Цикл одержання повідомлень

    while(GetMessage(&lpMsg, hWnd, 0, 0)) { //Получаем сообщение из очереди
            TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
            DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
        }
    return(lpMsg.wParam);
    }

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
                        WPARAM wParam, LPARAM lParam)
    {
    HDC hdc; //создаём контекст устройства
    PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода

    void arrow(float fi, int px,int py){

            int lx,ly,rx,ry; //px,py,
           // px=150; py=60;
            lx = px+15*cos(fi+0.3);
            rx = px+15*cos(fi-0.3);
            ly = py+15*sin(fi+0.3);
            ry = py+15*sin(fi-0.3);
            MoveToEx(hdc, lx, ly, NULL);
            LineTo(hdc, px, py);
            LineTo(hdc, rx, ry);
         //  return 0;
      }



//Цикл обработки сообщений
    switch(messg){
    //сообщение рисования
        case WM_PAINT :

            hdc=BeginPaint(hWnd, &ps);

            int n=12;
            char *nn[12] = {"1","2","3","4","5","6","7","8","9","10",
                       "11","12","13","14","15","16","17","18","19","20"};
            int nx[12] = {};
            int ny[12] = {};
            int dx = 16, dy = 16, dtx = 5;
            int i, j;
            int radius = 200;
            int centreX = 400;
            int centreY = 300;
            for (int i = 0; i < n; i++){
                nx[i] = centreX + radius * cos(2*PI*i/(n));
                ny[i] = centreY + radius * sin(2*PI*i/(n));
            }

            HPEN BPen = CreatePen(PS_SOLID, 2, RGB(50, 0, 255));
            HPEN KPen = CreatePen(PS_SOLID, 1, RGB(20, 20, 5));

        srand(0421);
        double** T = randm(n, n);
         double coef = 1.0 - 2*0.005 - 1*0.005 - 0.27;
        double** A = mulmr(coef, T, n, n);

             for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%g ", A[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        /*double**B=symmetricalMatrix(A,n,n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%g ", B[i][j]);
            }
            printf("\n");
        }*/

        //powgraph(A, n, n,B);

        printf("\n");
        //wayslength(A,n,n);
        connectionMatrix(A,n);

int nx0, ny0, Radius;
SelectObject(hdc, KPen);
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                double fi = PI + acos((nx[j]-nx[i])/(sqrt((nx[j]-nx[i])*(nx[j]-nx[i])+(ny[j]-ny[i])*(ny[j]-ny[i]))));
                    if (A[i][j] == 1){
                            if (i == j){
                                    if(i <= (n-1)/4){
                                Arc(hdc, nx[j], ny[j], nx[j]+40, ny[j]+40,    nx[j], ny[j], nx[j], ny[j]);
                                arrow(0, nx[j]+16, ny[j]+1);
                                }
                                    else if(i > (n-1)/4 && i <= (n-1)/2  ){
                                        Arc(hdc, nx[j], ny[j], nx[j]-40, ny[j]+40,    nx[j], ny[j], nx[j], ny[j]);
                                         arrow(PI, nx[j]-16, ny[j]+1);
                                    }
                                    else if(i > (n-1)/2 && i <= (3*(n-1))/4 ){
                                        Arc(hdc, nx[j], ny[j], nx[j]-40, ny[j]-40,    nx[j], ny[j], nx[j], ny[j]);
                                         arrow(PI, nx[j]-16, ny[j]-2);
                                    }
                                     else {
                                        Arc(hdc, nx[j], ny[j], nx[j]+40, ny[j]-40,    nx[j], ny[j], nx[j], ny[j]);
                                         arrow(-PI/2, nx[j], ny[j]-16);
                                    }
                                continue;
                           } else if  ((A[j][i]==1) && (i>j)) {
                                nx0=((nx[i]+nx[j])/2)-((ny[i]-ny[j]));
                                ny0=((ny[i]+ny[j])/2)+((nx[i]-nx[j]));
                                Radius=(sqrt(pow(nx[j]-nx0, 2)+pow(ny[j]-ny0, 2)));
                                Arc(hdc, nx0-Radius, ny0-Radius, nx0+Radius, ny0+Radius, nx[i], ny[i], nx[j], ny[j]);
                                double fi2=atan2(ny[i]-ny[j],nx[i]-nx[j])-atan2(sqrt(pow(nx[i]-nx[j],2)+pow(ny[i]-ny[j],2))/2,Radius);
                                arrow(fi2,nx[j]+16*cos(fi2),ny[j]+16*sin(fi2));
                                continue;
                            }
                        MoveToEx(hdc, nx[i], ny[i], NULL);
                        LineTo(hdc, nx[j], ny[j]);

                        if(ny[j] < ny[i]) fi *= -1;
                        arrow(fi, nx[j]+16*cos(fi), ny[j]+16*sin(fi));

                    }
                }
            }

Ellipse(hdc, 100, 100, 38, 38);
TextOut(hdc, 55, 50, "K1",5 );


        SelectObject(hdc, BPen);
           for(i=0;i < n;i++){
              Ellipse(hdc, nx[i]-dx,ny[i]-dy,nx[i]+dx,ny[i]+dy);
              TextOut(hdc, nx[i]-dtx,ny[i]-dy/2,  nn[i], 2);
            }

            EndPaint(hWnd, &ps);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return(DefWindowProc(hWnd, messg, wParam, lParam));
    }
    return 0;
}

