#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/*	This function will returns the callback standard output.
 * Standard error will still be displayed on screen. Standard 
 * output is reset back to normal after use. It is similar to php
 * ob_start() ... expected that this one use a callback.
 *
 *	If result is nullptr, then we experianced issues while creating 
 * or reading the file. Prehaps user don't have access to /tmp/ dir ?
 *
 */
char	*ob(void	(*callback)())
{
	int	out;
	int	save_out;
	char	*buffer;
	long	length;
	FILE	*f;
	char	*temporary;
	char 	fname[] = "/tmp/temp.XXXXXXXX";

	// create q temporary file and redirect stdout
	temporary = mktemp(fname);
	out = open(temporary, O_RDWR|O_CREAT|O_APPEND, 0600);
	save_out = dup(fileno(stdout));
	dup2(out, fileno(stdout));
	// run the callback and save its result to a file
	callback();
	// reset and close stdout redirection to file
	fflush(stdout); 
	close(out);
	dup2(save_out, fileno(stdout));
	close(save_out);
	// read created file content
	buffer = 0;
	length = 0;
	f = fopen (temporary, "rb");
	if (f)
	{
		fseek (f, 0, SEEK_END);
		length = ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = malloc (length);
		if (buffer)
		{
			fread (buffer, 1, length, f);
		}
		fclose (f);
		unlink(temporary);
	}
	return (buffer);
}
