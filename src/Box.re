module Css = {
  let box = [%cx
    {|
    padding: 1em;
    border: 1px solid black;
    background-color: hotpink;
    color: snow;
    text-align: center;
  |}
  ];
};

[@react.component]
let make = (~label) => <div className=Css.box> {React.string(label)} </div>;
