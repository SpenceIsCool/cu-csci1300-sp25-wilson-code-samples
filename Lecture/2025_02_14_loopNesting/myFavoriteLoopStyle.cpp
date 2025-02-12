int idk()
{
    bool keepGoing = true;
    int i = 0;
    while ( keepGoing )
    {
        cout << "Hello" << endl;
        i++;
        if ( i > 5 )
        {
            keepGoing = false;
        }
    }
    return 1;
}
