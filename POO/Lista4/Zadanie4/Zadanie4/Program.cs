using System.Text;

public class TagBuilder

{

    public TagBuilder() { }



    public TagBuilder(string TagName, TagBuilder Parent)

    {

        this.tagName = TagName;

        this.parent = Parent;

    }


    public  bool IsIndnted;
    public  int Indentation;
    public int currI = 0;
    private string tagName;

    private TagBuilder parent;

    private StringBuilder body = new StringBuilder();

    private Dictionary<string, string> _attributes = new Dictionary<string, string>();



    public TagBuilder AddContent(string Content)

    {
        for (int i = 0; i < currI; i++)
            for (int j = 0; j < Indentation; j++)
            {
                body.Append(" ");
            }
        body.Append(Content);
        body.Append("\n");
        return this;

    }



    public TagBuilder AddContentFormat(string Format, params object[] args)

    {
        for(int i = 0;i<currI;i++)
            for (int j = 0; j < Indentation; j++)
            {
                body.Append(" ");
            }
        body.AppendFormat(Format, args);
        body.Append("\n");
        return this;

    }



    public TagBuilder StartTag(string TagName)

    {

        TagBuilder tag = new TagBuilder(TagName, this);
        tag.IsIndnted = this.IsIndnted;
        tag.Indentation = this.Indentation;
        tag.currI = this.currI + 1;

        return tag;

    }



    public TagBuilder EndTag()

    {

        parent.AddContent(this.ToString());

        return parent;

    }



    public TagBuilder AddAttribute(string Name, string Value)

    {

        _attributes.Add(Name, Value);

        return this;

    }



    public override string ToString()

    {

        StringBuilder tag = new StringBuilder();

        // preamble

        if (!string.IsNullOrEmpty(this.tagName))

            tag.AppendFormat("<{0}", tagName);



        if (_attributes.Count > 0)

        {

            tag.Append(" ");

            tag.Append(

                string.Join(" ",

                    _attributes

                        .Select(

                            kvp => string.Format("{0}='{1}'", kvp.Key, kvp.Value))

                        .ToArray()));

        }



        // body/ending

        if (body.Length > 0)

        {

            if (!string.IsNullOrEmpty(this.tagName) || this._attributes.Count > 0)
                tag.Append(">");
            tag.Append("\n");
            
            tag.Append(body.ToString());

            if (!string.IsNullOrEmpty(this.tagName))
            {
                for (int i = 0; i < currI-1; i++)
                    for (int j = 0; j < Indentation; j++)
                    {
                        tag.Append(" ");
                    }
                    tag.AppendFormat("</{0}>", this.tagName);
            }

                
            
        }

        else

            if (!string.IsNullOrEmpty(this.tagName))

            tag.Append("/>");


        return tag.ToString();

    }

}
public class Program
{
    public static void Main()
    {
        var tag = new TagBuilder();
        tag.IsIndnted = true;
        tag.Indentation = 4;
        var script =

             tag.StartTag("parent")

                 .AddAttribute("parentproperty1", "true")

                 .AddAttribute("parentproperty2", "5")

                     .StartTag("child1")

                     .AddAttribute("childproperty1", "c")

                     .AddContent("childbody")

                     .EndTag()

                     .StartTag("child2")

                     .AddAttribute("childproperty2", "c")

                     .AddContent("childbody")

                     .EndTag()

                 .EndTag()

                 .StartTag("script")

                 .AddContent("$.scriptbody();")

                 .EndTag()

                 .ToString();
        Console.WriteLine(script);
    }
}