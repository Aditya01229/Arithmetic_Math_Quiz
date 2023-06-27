// #include "basicfunc.c"

// 10 x (1 - 99), 2digits x 1digit(0 - 9)
// This code is for framing questions arrays for level 1
int multlevel1(int *p1, int *p2)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(10, 99);
        int temp2 = printRandoms(1, 9);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
    }
    *(p2 + 9) = 10;
    // randomize(p1, 10);
    // randomize(p2, 10);
    return 0;
}

// 2digits x 2digit(up to 50)
// This code is for framing questions arrays for level 2
int multlevel2(int *p1, int *p2)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(10, 99);
        int temp2 = printRandoms(10, 50);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
    }
    return 0;
}

// 3digits x 1 or 2digit(1 - 50)
// This code is for framing questions arrays for level 3
int multlevel3(int *p1, int *p2)
{
    for (int i = 0; i < 10; i++)
    {
        int temp1 = printRandoms(100, 999);
        int temp2 = printRandoms(1, 50);
        *(p1 + i) = temp1;
        *(p2 + i) = temp2;
    }
    return 0;
}

// This function is for displaying the questions of multiplications according to the level input by user..
int printmult(int lvl)
{

    int crt = 0;
    int arr1[10], arr2[10];
    char name[10];
    printf("Enter your name:");
    scanf("%s", name);

    if (lvl == 1)
    {
        multlevel1(arr1, arr2);
    }
    if (lvl == 2)
    {
        multlevel2(arr1, arr2);
    }
    if (lvl == 3)
    {
        multlevel3(arr1, arr2);
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
        co = arr1[i] * arr2[i];
        options(op, co);
        printf("\nQuestion %d: %d x %d = ?", i + 1, arr1[i], arr2[i]);
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
    temp = fopen("files/mult/temp.txt", "w");
    fputs(name, temp);
    fprintf(temp, " %d %.3f\n", (crt * 10), (total_time / 1000));
    if (lvl == 1)
    {
        ptr = fopen("files/mult/mult1.txt", "r");
    }
    else if (lvl == 2)
    {
        ptr = fopen("files/mult/mult2.txt", "r");
    }
    else if (lvl == 3)
    {
        ptr = fopen("files/mult/mult3.txt", "r");
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
        remove("files/mult/mult1.txt");
        rename("files/mult/temp.txt", "files/mult/mult1.txt");
    }
    else if (lvl == 2)
    {
        remove("files/mult/mult2.txt");
        rename("files/mult/temp.txt", "files/mult/mult2.txt");
    }
    else if (lvl == 3)
    {
        remove("files/mult/mult3.txt");
        rename("files/mult/temp.txt", "files/mult/mult3.txt");
    }
}

void multhistory()
{

    FILE *ptr = NULL;
    printf("\nSome recent history are:");
    ptr = fopen("files/mult/mult1.txt", "r");
    printf("\n\n....................................................");
    printf("\n                   Level 1\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/mult/mult2.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 2\n");
    printfile(ptr);
    fclose(ptr);
    ptr = fopen("files/mult/mult3.txt", "r");
    printf("\n\n\n\n....................................................");
    printf("\n                   Level 3\n");
    printfile(ptr);
    fclose(ptr);
}


void multreset(){
    FILE *ptr = NULL;
    ptr = fopen("files/mult/mult1.txt", "w");
    fclose(ptr);
    ptr = fopen("files/mult/mult2.txt", "w");
    fclose(ptr);
    ptr = fopen("files/mult/mult3.txt", "w");
    fclose(ptr);
}