//
//  main.c
//  project3
//
//  Created by Brandon Johns on 11/5/19.
//  Copyright © 2019 Brandon Johns. All rights reserved.
//

#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

//function
void ProcessProblem(int pid, int status);

int main(void)
{
    /// creates parameteers for the process to feed in the function
    int pid;
    int status;
    printf("\n");
    ProcessProblem(pid,status);
    printf("\n");
    
}
void ProcessProblem(int pid, int status)
{
    printf("parent before fork: ");
    printf("\n");

    // this sets pid to the fork in order to create the seperate process
    pid = fork();
    
    // statement of pid and parent process
    printf("I am your Daddy and my name is <pid-of the-parent-process>\n");
    
    //making sure there isnt an error in the fork.
    if(pid == -1)
    {
        // if there is an error int he pid
        printf("error in the forking proceses ");
        exit(true);
    }
    else if (pid == false)
    {
        printf("\n");
        printf("child process: ");
        printf("\n");
        printf("Daddy My name is <pid-of-the-child>");
        printf("\n");
    }
    else
    {
        // waiting for child end so no orphans or zombines
        // wait receives the address of the status
        wait(&status);
        printf("parent after wait: ");
        printf("\n");
        printf("I am your Daddy and my name is <pid-of the-parent-process>\n");
    }
}

