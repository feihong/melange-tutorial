type gap =
  | Sm
  | Md
  | Lg;

type align =
  | Center
  | Left
  | Right;

module Css = {
  let stack = [%cx {|
    display: flex;
    flex-direction: column;
  |}];

  let gap = value => {
    let value =
      switch (value) {
      | Sm => `em(0.5)
      | Md => `em(1.0)
      | Lg => `em(1.5)
      };
    [%cx {|
      gap: $(value);
    |}];
  };

  let align = value => {
    let value =
      switch (value) {
      | Left => `flexStart
      | Center => `center
      | Right => `flexEnd
      };
    [%cx {|
      align-items: $(value);
    |}];
  };
};

[@react.component]
let make = (~gap: option(gap)=?, ~align: option(align)=?, ~children) =>
  <div
    className={
      Css.stack
      ++ " "
      ++ (gap |> Option.map(Css.gap) |> Option.value(~default=""))
      ++ " "
      ++ (align |> Option.map(Css.align) |> Option.value(~default=""))
    }>
    children
  </div>;
