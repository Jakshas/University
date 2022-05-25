using System.Text;

class CaesarStream : Stream
{
    Stream stream;
    int offset;

    public CaesarStream(Stream stream, int offset)
    {
        this.stream = stream;
        this.offset = offset;
    }

    public override int Read(byte[] buffer, int offset, int count)
    {
        var readStream = this.stream.Read(buffer, offset, count);

        for (int i = 0; i < buffer.Length; i++)
        {
            buffer[i] = (byte)(buffer[i] + this.offset);
        }

        return readStream;
    }

    public override void Write(byte[] buffer, int offset, int count)
    {
        var newBuffer = new byte[buffer.Length];

        for (int i = 0; i < buffer.Length; i++)
        {
            newBuffer[i] = (byte)(buffer[i] + this.offset);

        }

        this.stream.Write(newBuffer, offset, count);
    }

    public override bool CanRead => stream.CanRead;
    public override bool CanSeek => stream.CanSeek;
    public override bool CanWrite => stream.CanWrite;
    public override long Length => stream.Length;
    public override long Position { get => stream.Position; set => stream.Position = value; }
    public override void Flush() { stream.Flush(); }
    public override long Seek(long offset, SeekOrigin origin) { return stream.Seek(offset, origin); }
    public override void SetLength(long value) { stream.SetLength(value); }
}

class Program
{
    static void Main(string[] args)
    {
        const string input = "abcdefghijklmnoprstuwxyz";

        FileStream fileToWrite = File.Create("input.txt");
        CaesarStream caeToWrite = new CaesarStream(fileToWrite, 5);
        caeToWrite.Write(Encoding.ASCII.GetBytes(input));
        fileToWrite.Close();
        Console.WriteLine("'{0}'", input);

        FileStream fileToRead = File.OpenRead("input.txt");
        CaesarStream caeToRead = new CaesarStream(fileToRead, -5);
        var bytes = new byte[1000];
        caeToRead.Read(bytes);
        Console.WriteLine("'{0}'", Encoding.ASCII.GetString(bytes));
    }
}