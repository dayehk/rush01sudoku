int     **fillCell(int **num, int row, int col)
{
        int **nb;
        int validation;
        int value;

        if  (num[row][col] != 0)
        {

                if (col != 8)
                        return(fillCell(**num, row, col + 1));
                else if ( row != 8)
                {
                        col = 0;
                        return(fillCell(**num, row + 1, col);
                }
        }
        else
        {
                //
                validation = 0;

                j = 0;
                value = 1;

                while (value <= 9)
                {
                        validation = avlabl(**num, row, col, value);
                        if (validation == 1)
                        {
                                num[row][col] = value;
                                return(num[row][col]);
                                break;
                        }
                        else
                                value++;
                }
}



                (NULL);

