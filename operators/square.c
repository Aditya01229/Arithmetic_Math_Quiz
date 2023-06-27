// #include "basicfunc.c"

// This code is for framing questions arrays for level 1
void squarelevel1(int *p1)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(1, 20);
        *(p1 + i) = temp1;
    }
}

// This code is for framing questions arrays for level 2
void squarelevel2(int *p1)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(20, 50);
        *(p1 + i) = temp1;
    }
}

// This code is for framing questions arrays for level 3
void squarelevel3(int *p1)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(50, 100);
        *(p1 + i) = temp1;
    }
}

// This function is for displaying the questions of multiplications according to the level input by user..
int printsquare(int lvl)
{

    int crt = 0;
    int arr1[10];
    char name[10];
    printf("Enter your name:");
    scanf("%s", name);

    if (lvl == 1)
    {
        squarelevel1(arr1);
    }
    if (lvl == 2)
    {
        squarelevel2(arr1);
    }
    if (lvl == 3)
    {
        squarelevel3(arr1);
    }
    randomize(arr1, 10);
    printf("\nLet's Start the Quiz.\nGive answer in 1, 2, 3, 4.");
    clock_t t;
    double total_time;
    t = clock();
    for (int i = 0; i < 10; i++)
    {
        int op[4], co, ans;
        co = arr1[i] * arr1[i];
        options(op, co);
        printf("\nQuestion %d: %d^2 = ?", i + 1, arr1[i]);
        printf("\nOptions:");
        for (int j = 0; j < 4; j++)
        {
            printf("\n%d) %d", (j + 1), op[j]);
        }
        printf("\nAnswer:");
        scanf("%d", &ans);
        if (op[ans - 1] == co)
        {
            crt += 1;
            printf("Woohoo! Correct Answer!\n\n\n");
        }
        else
        {
            printf("Oops! Correct Answer is: %d\n\n\n", co);
        }
    }
    t = clock() - t;
    total_time = ((double)t); // This is the total time consumes for answering the questions.

    printf("\nYou answered %d questions correct in %.3f seconds!\nAnd your accuracy is %d%%", crt, total_time / 1000, (crt * 10));

    // File Handling for saving the records!
    FILE *ptr = NULL;
    FILE *temp = NULL;
    temp = fopen("files/square/temp.txt", "w");
    fputs(name, temp);
    fprintf(temp, " %d %.3f\n", (crt * 10), (total_time / 1000));
    if (lvl == 1)
    {
        ptr = fopen("files/square/square1.txt", "r");
    }
    else if (lvl == 2)
    {
        ptr = fopen("files/square/square2.txt", "r");
    }
    else if (lvl == 3)
    {
        ptr = fopen("files/square/square3.txt", "r");
    }
    char ch;
    while ((ch = getc(ptr)) != EOF)
    {
        fputc(ch, temp);
    }
    fclose(temp);
    fclose(ptr);

    if (lvl == 1)
    {
        remove("files/square/square1.txt");
        rename("files/square/temp.txt", "files/square/square1.txt");
    }
    else if (lvl == 2)
    {
        remove("files/square/square2.txt");
        rename("files/square/temp.txt", "files/square/square2.txt");
    }
    else if (lvl == 3)
    {
        remove("files/square/square3.txt");
        rename("files/square/temp.txt", "files/square/square3.txt");
    }
}

void squarehistory()
{

    FILE *ptr = NULL;
    printf("\nSome recent history are:");
    ptr = fopen("files/square/square1.txt", "r");
    printf("\n\n....................................................");
    printf("\n                   Level 1\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/square/square2.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 2\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/square/square3.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 3\n");
    printfile(ptr);
    fclose(ptr);
}


void squarereset(){
    FILE *ptr = NULL;
    ptr = fopen("files/square/square1.txt", "w");
    fclose(ptr);
    ptr = fopen("files/square/square2.txt", "w");
    fclose(ptr);
    ptr = fopen("files/square/square3.txt", "w");
    fclose(ptr);
}