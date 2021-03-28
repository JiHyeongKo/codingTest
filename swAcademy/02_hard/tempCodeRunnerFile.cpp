for(int i = 1; i < n; i=i+2)
    {
        if (buffer[i] == '+')
        {
            value[i/2] = value[i/2] + value[i/2 + 1];

            n = n-2;
            buffer[i-1] = buffer[i-1] + buffer[i+1];
        }
    }