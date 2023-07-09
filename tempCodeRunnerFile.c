    time(&session_end);
    time_elapsed=session_end-session_start;
    printf("Time Measure  %d in seconds",time_elapsed);
    close(new_socket);
	