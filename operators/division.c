// #include "basicfunc.c"

// This code is for framing questions arrays for level 1
int divlevel1(int *p1, int *p2, int *p3)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(2, 11);
        int temp2 = printRandoms(2, 5);
        int temp3 = printRandoms(2, 10);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
        *(p3 + i) = temp3;
    }
    *(p2 + 9) = 10;
    randomize(p1, 10);
    randomize(p2, 10);
    randomize(p2, 10);
    return 0;
}

// This code is for framing questions arrays for level 2
int divlevel2(int *p1, int *p2, int *p3)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(27, 39);
        int temp2 = printRandoms(11, 20);
        int temp3 = printRandoms(11, 19);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
        *(p3 + i) = temp3;
    }
    return 0;
}

// This code is for framing questions arrays for level 3
int divlevel3(int *p1, int *p2, int *p3)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(20, 40);
        int temp2 = printRandoms(41, 50);
        int temp3 = printRandoms(21, 30);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
        *(p3 + i) = temp3;
    }
    return 0;
}

// This function is for displaying the questions of divisions according to the level input by user..
int printdiv(int lvl)
{
    int crt = 0;
    int arr1[10], arr2[10], arr3[10];
    char name[10];
    printf("Enter your name:");
    scanf("%s", name);

    if (lvl == 1)
    {
        divlevel1(arr1, arr2, arr3);
    }
    if (lvl == 2)
    {
        divlevel2(arr1, arr2, arr3);
    }
    if (lvl == 3)
    {
        divlevel3(arr1, arr2, arr3);
    }
    randomize(arr1, 10);
    randomize(arr2, 10);
    printf("\nLet's Start the Quiz.\nGive answer in 1, 2, 3, 4.");
    clock_t t;
    double total_time;
    t = clock();
    for (int i = 0; i < 10; i++)
    {
        int op[4], co, ans;
        co = arr1[i] * arr2[i] * arr3[i] / arr3[i];
        options(op, co);
        printf("\nQuestion %d: %d / %d = ?", i + 1, arr1[i] * arr2[i] * arr3[i], arr3[i]);
        printf("\nOptions:");
        for (int j = 0; j < 4; j++)
        {
            printf("\n%d) %d", (j + 1), op[j]);
        }
        printf("\nAnswer:");
        scanf("%d", &ans);
        if (op[ans - 1] == co)
        {
            printf("Woohoo! Correct Answer!\n\n\n");
            crt += 1;
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
    temp = fopen("files/div/temp.txt", "w");
    fputs(name, temp);
    fprintf(temp, " %d %.3f\n", (crt * 10), (total_time / 1000));
    if (lvl == 1)
    {
        ptr = fopen("files/div/div1.txt", "r");
    }
    else if (lvl == 2)
    {
        ptr = fopen("files/div/div2.txt", "r");
    }
    else if (lvl == 3)
    {
        ptr = fopen("files/div/div3.txt", "r");
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
        remove("files/div/div1.txt");
        rename("files/div/temp.txt", "files/div/div1.txt");
    }
    else if (lvl == 2)
    {
        remove("files/div/div2.txt");
        rename("files/div/temp.txt", "files/div/div2.txt");
    }
    else if (lvl == 3)
    {
        remove("files/div/div3.txt");
        rename("files/div/temp.txt", "files/div/div3.txt");
    }

    return crt;
}

void divhistory()
{

    FILE *ptr = NULL;
    printf("\nSome recent history are:");
    ptr = fopen("files/div/div1.txt", "r");
    printf("\n\n....................................................");
    printf("\n                   Level 1\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/div/div2.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 2\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/div/div3.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 3\n");
    printfile(ptr);
    fclose(ptr);
}

void divreset(){
    FILE *ptr = NULL;
    ptr = fopen("files/div/div1.txt", "w");
    fclose(ptr);
    ptr = fopen("files/div/div2.txt", "w");
    fclose(ptr);
    ptr = fopen("files/div/div3.txt", "w");
    fclose(ptr);
}